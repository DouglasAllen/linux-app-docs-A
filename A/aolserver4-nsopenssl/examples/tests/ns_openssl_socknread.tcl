# nsopenssl socket testing setup
# Copyright (c) 2001 by Scott S. Goodwin
# See http://scottg.net for more information

ns_log notice "loading test-socknread.tcl"

#proc do_socknread {timeout sock} {
#    set p "do_socknread"
#    set nread [ns_socknread $sock]
#    if !$nread {
#        set sel [ns_sockselect -timeout $timeout $sock {} {}]
#        if [string match "" [lindex $sel 0]] {
#            return -code error "ns_sockreadwait: Timeout waiting for remote"
#        }
#        set nread [ns_socknread $sock]
#    }
#    return $nread
#}


