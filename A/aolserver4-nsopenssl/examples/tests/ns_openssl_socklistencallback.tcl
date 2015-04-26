# nsopenssl socket testing setup
# Copyright (c) 2001 by Scott S. Goodwin
# See http://scottg.net for more information

ns_log notice "loading test-socklistencallback.tcl"

# socklistencallback
# NOTE: how do you stop listening on a listen callback?
ns_register_proc GET /do_socklistencallback do_socklistencallback
proc do_socklistencallback {} {
    ns_socklistencallback [nsv_get . httpaddr] [nsv_get . listenport] handle_socklistencallback
    set content [do_content "<b>tested ns_socklistencallback</b><br>"]
    set rc [do_write [do_header $content] $content]
}

# SSL socklistecallback
# NOTE: how do you stop listening on a listen callback?
ns_register_proc GET /do_ssl_socklistencallback do_ssl_socklistencallback
proc do_ssl_socklistencallback {} {
    ns_openssl_socklistencallback [nsv_get . httpaddr] [nsv_get . listensslport] handle_ssl_socklistencallback
    set content [do_content "<b>tested ns_openssl_socklistencallback</b><br>"]
    set rc [do_write [do_header $content] $content]
}

proc handle_socklistencallback {rfd wfd} {
    set p "handle_socklistencallback"
    ns_log notice "$p: a client has connected to the socket"
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
<p>Great! We were able to do a listen-callback on a non-SSL socket,
read the client HTTP header and send back this HTML page. Hit the back
button to return to the test page.
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

proc handle_ssl_socklistencallback {rfd wfd} {
    set p "handle_ssl_socklistencallback"
    ns_log notice "$p: a client has connected to the SSL socket"
    while {[set line [string trim [gets $rfd]]] != ""} {
	lappend headers $line
    }
    ns_log notice "$p: CLIENT HTTP HEADERS:"
    # always catch the first attempt to print or log something
    # that was supposed to be read from the connection. If you're
    # using a test certificate, MSIE aborts the connection and then
    # makes a new connection after you accept the certificate. In this
    # case it means that $headers won't exist and trying to ns_log it
    # causes an error.
    if { [catch {ns_log notice "$p: $headers"} fid] } {
	ns_log notice "user aborted connection - MSIE probably being used"
	# Unlike in the test-socklisten2.tcl test script, we don't have to
        # go back to listening because the listener is still there. When
        # MSIE makes its second connection after the user has accepted the
        # untrusted certificate, this callback proc is run again.
	return
    }

    set content_htm \
"<html>
<head>
<title>ssl test</title>
</head>
<body>
<p>Great! We were able to do a listen-callback on an SSL socket,
read the client HTTP header and send back this HTML page. Hit the back
button to return to the test page.
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

ns_log notice "done loading test-socklistencallback.tcl"
