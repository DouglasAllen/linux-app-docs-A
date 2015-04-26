# /etc/aolserver/ssl.tcl
# LEG28032005
#

#### this file is not user servicable ##############################

# TODO: ca files, opcional 

$ns_section "ns/server/${server}/module/nsopenssl/sslcontexts"
$ns_param https      "SSL context for access to the website"
$ns_param outgoing   "SSL context for outgoing script socket connections"
$ns_param incoming   "SSL context for incoming script socket connections"

$ns_section "ns/server/${server}/module/nsopenssl/defaults"
$ns_param server     https
$ns_param client     outgoing
$ns_param server     incoming


$ns_section "ns/server/${server}/module/nsopenssl/ssldrivers"
$ns_param https  "Driver for access to the website"

$ns_section "ns/server/${server}/module/nsopenssl/ssldriver/https"
$ns_param sslcontext            https
$ns_param port                  $conf($server,httpsport)
$ns_param hostname              $conf($server,hostname)
$ns_param address               $conf($server,httpsaddress)

# For HTTPS-Access to our website
# NSD-driven connections:

$ns_section "ns/server/${server}/module/nsopenssl/sslcontext/https"
$ns_param Role                            server

$ns_param ModuleDir            [conffile ${certdir}]
$ns_param CertFile             ${server}.crt
$ns_param KeyFile              ${server}.pem
$ns_param Protocols            "SSLv2, SSLv3, TLSv1"
$ns_param CipherSuite          "ALL:!ADH:RC4+RSA:+HIGH:+MEDIUM:+LOW:+SSLv2:+EXP"
$ns_param SessionCache         false
$ns_param SessionCacheID       1
$ns_param SessionCacheSize     512
$ns_param SessionCacheTimeout  300
$ns_param PeerVerify           false
$ns_param PeerVerifyDepth      3
$ns_param CADir                [conffile ${ca_dir}]
$ns_param CAFile               ${server}.ca
$ns_param Trace                false

# For listening and accepting SSL connections via Tcl/C API:

$ns_section "ns/server/${server}/module/nsopenssl/sslcontext/incoming"
$ns_param Role                 server
$ns_param ModuleDir            [conffile ${certdir}]
$ns_param CertFile             ${server}.crt
$ns_param KeyFile              ${server}.pem
$ns_param Protocols            "SSLv2, SSLv3, TLSv1"
$ns_param CipherSuite          "ALL:!ADH:RC4+RSA:+HIGH:+MEDIUM:+LOW:+SSLv2:+EXP"
$ns_param SessionCache         false
$ns_param SessionCacheID       2
$ns_param SessionCacheSize     512
$ns_param SessionCacheTimeout  300
$ns_param PeerVerify           false
$ns_param PeerVerifyDepth      3
$ns_param CADir                [conffile ${ca_dir}]
$ns_param CAFile               ${server}_internal.ca
$ns_param Trace                false


# Outgoing SSL connections

$ns_section "ns/server/${server}/module/nsopenssl/sslcontext/outgoing"

$ns_param Role                 client
$ns_param ModuleDir            [conffile ${certdir}]
$ns_param CertFile             ${server}.crt
$ns_param KeyFile              ${server}.pem
$ns_param Protocols            "SSLv2, SSLv3, TLSv1"
$ns_param CipherSuite          "ALL:!ADH:RC4+RSA:+HIGH:+MEDIUM:+LOW:+SSLv2:+EXP"
$ns_param SessionCache         false
$ns_param SessionCacheID       3
$ns_param SessionCacheSize     512
$ns_param SessionCacheTimeout  300
$ns_param PeerVerify           false
$ns_param PeerVerifyDepth      3
$ns_param CADir                [conffile ${ca_dir}]
$ns_param CAFile               ${server}.ca
$ns_param Trace                false

# OpenSSL library support:
#$ns_param RandomFile                      /some/file
$ns_param SeedBytes                       1024

# Quirk to make OpenACS recognise 2.0 Style httpsport configuration
#
$ns_section ns/server/${server}/module/nsopenssl
$ns_param ServerPort	$conf($server,httpsport)
