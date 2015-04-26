# /etc/aolserver4/database.tcl
# LEG28032005
#
# Database drivers 
#

# TODO:  Multiple database configurations

# Prepare configuration/default values.
set database $conf(${server},database)
set db_name  $conf(${server},dbname)

# db_host:
if [info exists conf(${server},dbhost)] {
    set db_host  $conf(${server},dbhost)
} else {
    set db_host {}
}

# db_port:
if [info exists conf(${server},dbport)] {
    set db_port $conf(${server},dbport)
} else {
    set db_port {}
}

# db_user:
if ![info exists conf(${server},dbuser)] {
    set db_user $db_name
} else {
    set db_user  $conf(${server},dbuser)
}
# db_password:
if { $database == "oracle" } {
    set db_password  $conf(${server},dbpass)
}	

$ns_section "ns/db/drivers" 
if { $database == "oracle" } {
    $ns_param   ora8            [libfile bin ora8.so]
} else {
    $ns_param   postgres        [libfile bin nspostgres.so]
}

# 
# Database Pools: This is how AOLserver  ``talks'' to the RDBMS. You need 
# three for OpenACS: main, log, subquery. Make sure to replace ``yourdb'' 
# and ``yourpassword'' with the actual values for your db name and the 
# password for it.

# AOLserver can have different pools connecting to different databases 
# and even different different database servers.
# 
$ns_section ns/db/pools 
$ns_param   ${server}_pool1       "$server Pool 1"
$ns_param   ${server}_pool2       "$server Pool 2"
$ns_param   ${server}_pool3       "$server Pool 3"

$ns_section ns/db/pool/${server}_pool1
$ns_param   maxidle            1000000000
$ns_param   maxopen            1000000000
$ns_param   connections        5
$ns_param   verbose            $debug
$ns_param   extendedtableinfo  true
$ns_param   logsqlerrors       $debug
if { $database == "oracle" } {
    $ns_param   driver             ora8
    $ns_param   datasource         {}
    $ns_param   user               $db_name
    $ns_param   password           $db_password
} else {
    $ns_param   driver             postgres 
    $ns_param   datasource         ${db_host}:${db_port}:${db_name}
    $ns_param   user               $db_user
    $ns_param   password           ""
} 

$ns_section ns/db/pool/${server}_pool2
$ns_param   maxidle            1000000000
$ns_param   maxopen            1000000000
$ns_param   connections        5
$ns_param   verbose            $debug
$ns_param   extendedtableinfo  true
$ns_param   logsqlerrors       $debug
if { $database == "oracle" } {
    $ns_param   driver             ora8
    $ns_param   datasource         {}
    $ns_param   user               $db_name
    $ns_param   password           $db_password
} else {
    $ns_param   driver             postgres 
    $ns_param   datasource         ${db_host}:${db_port}:${db_name}
    $ns_param   user               $db_user
    $ns_param   password           ""
} 

$ns_section ns/db/pool/${server}_pool3
$ns_param   maxidle            1000000000
$ns_param   maxopen            1000000000
$ns_param   connections        5
$ns_param   verbose            $debug
$ns_param   extendedtableinfo  true
$ns_param   logsqlerrors       $debug
if { $database == "oracle" } {
    $ns_param   driver             ora8
    $ns_param   datasource         {}
    $ns_param   user               $db_name
    $ns_param   password           $db_password
} else {
    $ns_param   driver             postgres 
    $ns_param   datasource         ${db_host}:${db_port}:${db_name}
    $ns_param   user               $db_user
    $ns_param   password           ""
} 

$ns_section ns/server/${server}/db
$ns_param   pools	"${server}_pool1,${server}_pool2,${server}_pool3" 
$ns_param   defaultpool  ${server}_pool1
