# Create test certificate authorities and certificates

# $Header: /cvsroot/aolserver/nsopenssl/ca/Makefile,v 1.2 2002/10/08 02:33:45 scottg Exp $

# In progress -- figure out if openssl will create the subdirs specified in the ca1.conf file,
# or if I have to manually do that here.

MKDIR      = /bin/mkdir -p
TOUCH      = /bin/touch

###############################################################################
# CA #1 - Web Server Certificate Signing

CA1          = ca1

ca1: ca1-dirs
	@openssl genrsa -des3 \
		-passout pass:$(CA1) \
		-out $(CA1)/$(CA1).key \
		1024
	@openssl req -new -x509 -days 365 \
		-config $(CA1).conf \
		-passin pass:$(CA1) \
		-key $(CA1)/$(CA1).key \
		-out $(CA1)/$(CA1).pem

ca1-dirs:
	@if [ ! -d $(CA1) ]; then \
		$(MKDIR) $(CA1); \
		$(MKDIR) $(CA1)/certificates; \
		$(MKDIR) $(CA1)/keys; \
		$(MKDIR) $(CA1)/csr; \
		$(MKDIR) $(CA1)/crl; \
		$(TOUCH) $(CA1)/index.txt; \
		echo '01' > $(CA1)/serial; \
	fi

###############################################################################
# CA #1 - Web Server Certificate

CA1_WEB_SERVER   = ca1-web-server

ca1-web-server: ca1
	@openssl genrsa \
		-out $(CA1)/keys/$(CA1_WEB_SERVER).pem \
		1024

	@openssl req -new \
		-config $(CA1).conf \
		-key $(CA1)/keys/$(CA1_WEB_SERVER).pem \
		-out $(CA1)/csr/$(CA1_WEB_SERVER).pem

	@openssl ca \
		-config $(CA1).conf \
		-key $(CA1) \
		-out $(CA1)/certificates/$(CA1_WEB_SERVER).pem \
		-infiles $(CA1)/csr/$(CA1_WEB_SERVER).pem

	@openssl verify \
		-CAfile $(CA1)/$(CA1).pem \
		$(CA1)/certificates/$(CA1_WEB_SERVER).pem

###############################################################################
# CA #2 - Client Certificate Signing

CA2          = ca2
CA2_ROOT     = $(CA2)

ca2: ca2-dirs
	@openssl genrsa -des3 \
		-passout pass:$(CA2) \
		-out $(CA2_ROOT)/$(CA2).key \
		1024
	@openssl req -new -x509 -days 365 \
		-config $(CA2).conf \
		-passin pass:$(CA2) \
		-key $(CA2_ROOT)/$(CA2).key \
		-out $(CA2_ROOT)/$(CA2).pem

ca2-dirs:
	@if [ ! -d $(CA2_ROOT) ]; then \
		$(MKDIR) $(CA2_ROOT); \
		$(MKDIR) $(CA2_ROOT)/certificates; \
		$(MKDIR) $(CA2_ROOT)/crl; \
	fi

###############################################################################
### END

# Take a look at the key in readable format
#openssl rsa -noout -text -in ca.key


# Take a look at the certificate in readable format
#openssl x509 -noout -text -in ca.crt
