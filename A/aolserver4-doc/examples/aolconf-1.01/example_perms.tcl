# LEG28032005
#
# This file implements the sample users/groups/permissions
# provided by the standard nsperm module

ns_section ns/servers/${server}/modules/nsperm/users
ns_param user ""
ns_param user nsadmin
ns_param user nobody

ns_section ns/servers/${server}/modules/nsperm/user/""
ns_param name       "The Public"

ns_section ns/servers/${server}/modules/nsperm/user/nsadmin
ns_param name       "Administrator"
ns_param password   ubphBI5lDzSYc

#ns_section ns/servers/${server}/modules/nsperm/user/nobody

# GROUPS:

ns_section ns/servers/${server}/modules/nsperm/groups
ns_param group       system
ns_param group       users
ns_param group       all
ns_param group       public

ns_section ns/servers/${server}/modules/nsperm/group/system
ns_param member      nsadmin


ns_section ns/servers/${server}/modules/nsperm/group/users
ns_param member      nsadmin
ns_param member      nobody

ns_section ns/servers/${server}/modules/nsperm/group/all
ns_param member      nsadmin
ns_param member      nobody
ns_param member      ""


ns_section ns/servers/${server}/modules/nsperm/group/public
ns_param member      ""

ns_section ns/servers/${server}/modules/nsperm/perms
#ns_param allowuser   "nsadmin::/dav"
#ns_param denyuser    "::/"
