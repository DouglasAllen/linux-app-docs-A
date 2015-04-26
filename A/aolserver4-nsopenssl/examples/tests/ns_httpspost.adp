<HTML>
<HEAD>
   <TITLE>ns_httpspost multipart test form target</TITLE>
</HEAD>
<BODY BGCOLOR="#ffffff">
<%

# Get form data and assign to variables

set r [ns_conn form $conn]

set username [ns_set get $r username]
set userpassword [ns_set get $r userpassword]

ns_puts "USERNAME = $username"
ns_puts "USERPASSWORD = $userpassword"

%>
</BODY></HTML>
