# Makefile
# LEG24042005: separated paths into aolconf.conf, don't overwrite
#              existing domains.cfg, fixes
# LEG04042005
#
# Makefile for aolconf - Aolserver Configuration
#
# this makefile is used for installation and packing of the respective
# files

# these go into SERVERHOME
TCLSCRIPTS = main.tcl server.tcl database.tcl ssl.tcl tdav.tcl

# these go into CONFDIR
CONFFILES = aolconf.conf

# these go into SBINDIR
SBINFILES = aolserver-php5-cgi-wrapper aolserver4-newdomain

# theses get packaged
PACKFILES = run nsperm_init.tcl example_perms.tcl tDAV.tcl \
	    aolserver4-init aolserver-php5-cgi-wrapper \
	    aolserver4-newdomain \
	    domains.cfg minimal.cfg $(TCLSCRIPTS) aolconf.conf \
	    Makefile NEWS TODO


include ./aolconf.conf


INSTALL = install
#INSTALL = @echo install

install:
	@echo Did you at least:
	@echo apt-get install aolserver4 aolserver4-nsopenssl
	@echo ?
	@echo Are you ready to overwrite nsperm\'s init.tcl?
	@echo ok, then run make real-install
	@echo
	@echo "Note: consider tDOM for WebDAV support"
	@echo "               aolserver4-nscache"
	@echo "               aolserver4-nspostgres for OpenACS/Database support"
	@echo "               aolserver4-nsldap for LDAP support"

real-install:
	# confscript & run
	$(INSTALL) $(TCLSCRIPTS) run $(SERVERHOME)
	# DAV
	$(INSTALL) -d -m 750 -o $(AOLUSR) -g $(AOLGRP) $(DAVLOCKS)
	$(INSTALL) -d -m 750 -o $(AOLUSR) -g $(AOLGRP) $(DAVPROPS)
	$(INSTALL) tDAV.tcl $(SERVERLIB)
	# nsperm
	$(INSTALL) nsperm_init.tcl $(SERVERLIB)/nsperm/init.tcl
	$(INSTALL) -d -m 2750 -o root -g $(AOLGRP) $(PERMS)
	$(INSTALL) example_perms.tcl $(PERMS)/main.tcl
	@echo Installed example permissions in $(PERMS)
	@echo The default password for nsadmin is "x".
	@echo Please modify it before activating tDAV or anything
	@echo else that uses nsperm authentication.
	# nsopenssl
	$(INSTALL) -d -m 2750 -o root -g $(AOLGRP) $(CERTS)
	$(INSTALL) $(STARTCRT) $(CERTS)/main.crt
	$(INSTALL) $(STARTKEY) $(CERTS)/main.pem
	# logs
	$(INSTALL) -d -m 2750 -o $(AOLUSR) -g $(ADMGRP) $(AOLLOG)/main
	# main conf
	@echo installing minimal configuration
	@[ -f $(CONFDIR)/domains.cfg ] || $(INSTALL) minimal.cfg $(CONFDIR)/domains.cfg
	@[ -f $(CONFDIR)/domains.cfg ] && $(INSTALL) minimal.cfg $(CONFDIR)
	$(INSTALL) domains.cfg $(CONFDIR)/example-domains.cfg
	$(INSTALL) $(CONFFILES) $(CONFDIR)
	# sysv-init
	$(INSTALL) aolserver4-init $(INITDIR)/aolserver4
	@echo Installed aolserver4 in $(INITDIR)
	@echo You must activate the script by yourself if you want to
	@echo use SysV style startup
	# cgi-wrapper
	$(INSTALL) aolserver-php5-cgi-wrapper $(SBINDIR)
	# utilities
	$(INSTALL) aolserver4-newdomain $(SBINDIR)

package:  
	mkdir -p aolconf-$(VERSION)
	cp $(PACKFILES) aolconf-$(VERSION)
	tar czf aolconf-$(VERSION).tgz aolconf-$(VERSION)
	rm -rf aolconf-$(VERSION)

directoryproc:
	$(INSTALL) directoryproc.tcl $(SERVERLIB)

fix:
	# fixing logdir
	chmod 2750 $(AOLLOG)
	chown -R $(AOLUSR):$(ADMGRP) $(AOLLOG)
	# fixing permfiles
	chmod 640 $(PERMS)/*
	chown root:$(AOLGRP) $(PERMS)/*
	# fixing certs
	chmod 640 $(CERTS)/*
	chown root:$(AOLGRP) $(CERTS)/*

.PHONY = install package

