# /etc/aolserver4/tdav.tcl
# LEG27032005
#

foreach share $conf($server,shares) {
    $ns_section ns/server/${server}/tdav/share/${share}
    $ns_param uri     $conf($server,$share,dav_uri)
    $ns_param options $conf($server,$share,dav_options)
    $ns_param propcommand tdav::prop::local
    $ns_param lockcommand tdav::lock::local
    $ns_param authcommand tdav::auth::local
    if [info exists conf($server,$share,dav_users)] {
	$ns_param users $conf($server,$share,dav_users)
    }
    if [info exists conf($server,$share,dav_groups)] {
	$ns_param groups $conf($server,$share,dav_groups)
    }
}
    
$ns_section ns/server/${server}/tdav/shares

foreach share $conf($server,shares) {
    $ns_param $share $conf($server,$share,dav_description)
}

$ns_section ns/server/${server}/tdav
$ns_param propdir ${vardir}/${package}/dav/${server}/properties
$ns_param lockdir ${vardir}/${package}/dav/${server}/locks
$ns_param defaultlocktimeout 300

# TODO: integrate this ones
#$ns_param directorycmd
#$ns_param redirects {}
# before and after request callbacks
# commented out, these are optional
#$ns_param beforecallback tdav::before
#$ns_param aftercallback tdav::after
