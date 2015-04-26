# nsopenssl socket testing setup
# Copyright (c) 2001 by Scott S. Goodwin
# See http://scottg.net for more information

ns_log notice "loading test-sockcallback.tcl"

# sockcallback
ns_register_proc GET /do_sockcallback do_sockcallback
proc do_sockcallback {} {
    set sock [ns_socklisten [nsv_get . httpaddr] [nsv_get . listenport]]
    ns_sockcallback $sock handle_sockcallback r
    set content [do_content "<b>tested ns_sockcallback</b><br>"]
    set rc [do_write [do_header $content] $content]
}

# SSL sockcallback
ns_register_proc GET /do_ssl_sockcallback do_ssl_sockcallback
proc do_ssl_sockcallback {} {
    set sock [ns_openssl_socklisten [nsv_get . httpaddr] [nsv_get . listensslport]]
    ns_openssl_sockcallback $sock handle_ssl_sockcallback r
    set content [do_content "<b>tested ns_openssl_sockcallback</b><br>"]
    set rc [do_write [do_header $content] $content]
}

proc handle_sockcallback {sock when} {
    set p "handle_sockcallback"
    ns_log notice "$p: a client has connected to the socket"
    set fds [ns_sockaccept $sock]
    set rfd [lindex $fds 0]
    set wfd [lindex $fds 1]
    ns_log notice "$p: RFD=$rfd; WFD=$wfd"
    while {[set line [string trim [gets $rfd]]] != ""} {
	lappend headers $line
    }
    ns_log notice "$p: CLIENT HTTP HEADERS:"
    ns_log notice "$p: $headers"

    set content_htm \
"<html>
<head>
<title>non-ssl test</title>
</head>
<body>
<p>Great! We were able to do a non-SSL sockcallback, read the client
HTTP header and send back this HTML page. Hit the back button to
return to the test page.
<p>Here ar the HTTP client headers you sent me:
<p>$headers
</body>
</html>"

    set myheader \
        "HTTP/1.0 200 Document follows
MIME-Version: 1.0
Content-Type: text/html
Content-Length: [string length $content_htm]"

    puts $wfd \
"$myheader


$content_htm"

    flush $wfd
    close $rfd
    close $wfd
}

proc handle_ssl_sockcallback {sock when} {
    set p "handle_ssl_sockcallback"
    ns_log notice "$p: a client has connected to the SSL socket"
    set fds [ns_openssl_sockaccept $sock]
    set rfd [lindex $fds 0]
    set wfd [lindex $fds 1]
    while {[set line [string trim [gets $rfd]]] != ""} {
	lappend headers $line
    }
    ns_log notice "$p: CLIENT HTTP HEADERS:"
    ns_log notice "$p: $headers"

    set content_htm \
"<html>
<head>
<title>ssl test</title>
</head>
<body>
<p>Great! We were able to do an SSL sockcallback, read the client
HTTP header and send back this HTML page. Hit the back button to
return to the test page.
<p>Here ar the HTTP client headers you sent me:
<p>$headers
</body>
</html>"

    set myheader \
        "HTTP/1.0 200 Document follows
MIME-Version: 1.0
Content-Type: text/html
Content-Length: [string length $content_htm]"

    puts $wfd \
"$myheader


$content_htm"

    flush $wfd
    close $rfd
    close $wfd
}

ns_log notice "done loading test-sockcallback.tcl"
