# nsopenssl socket testing setup
# Copyright (c) 2001 by Scott S. Goodwin
# See http://scottg.net for more information

ns_log notice "loading test-sockopen.tcl"

# non-SSL sockopen
# Connects to the server and reads the page specified by the url
ns_register_proc GET /do_sockopen do_sockopen
proc do_sockopen {} {
    set p "do_sockopen"
    set bytes 200
    set fds [ns_sockopen -nonblock [nsv_get . httpaddr] [nsv_get . port]]
    set rfd [lindex $fds 0]
    set wfd [lindex $fds 1]
    ns_log notice "$p: RFD=$rfd; WFD=$wfd"
    ns_log notice "$p: sending to server: GET /hardcodedurl HTTP/1.0<cr><lf><cr><lf>"
    puts $wfd "GET /hardcodedurl HTTP/1.0\r\n\r\n"
    flush $wfd
    while {[set line [string trim [gets $rfd]]] != ""} {
 	lappend headers $line
    }
    set page [read $rfd $bytes]
    close $rfd
    close $wfd
    ns_log notice "$p: first $bytes bytes of page:"
    ns_log notice "$page"
    set content [do_content "<b>tested ns_sockopen</b><br>"]
    set rc [do_write [do_header $content] $content]
}

# SSL sockopen
# Connects to the SSL server and reads the page specified by the url
ns_register_proc GET /do_ssl_sockopen do_ssl_sockopen
proc do_ssl_sockopen {} {
#   for {set i 0} {$i < 5000} {incr i} {
    set p "do_ssl_sockopen"
    set bytes 200
    set fds [ns_openssl_sockopen -nonblock [nsv_get . httpaddr] [nsv_get . sslport]]
    set rfd [lindex $fds 0]
    set wfd [lindex $fds 1]
    set validcert [lindex $fds 2]
    ns_log notice "$p: rfd=$rfd; wfd=$wfd; validcert=$validcert"
    if {$validcert} {
	ns_log notice "$p: server cert is valid"
    } else {
	ns_log notice "$p: server cert is invalid"
    }
    ns_log notice "$p: sending to server: GET /hardcodedurl HTTP/1.0<cr><lf><cr><lf>"
    puts $wfd "GET /hardcodedurl HTTP/1.0\r\n\r\n"
    flush $wfd
    while {[set line [string trim [gets $rfd]]] != ""} {
 	lappend headers $line
    }
    set page [read $rfd $bytes]
    close $rfd
    close $wfd
    ns_log notice "$p: first $bytes bytes of page:"
    ns_log notice "$page"
    set content [do_content "<b>tested ns_ssl_sockopen</b><br>"]
    set rc [do_write [do_header $content] $content]
#   }
}

ns_log notice "done loading test-sockopen.tcl"
