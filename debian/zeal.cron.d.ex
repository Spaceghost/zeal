#
# Regular cron jobs for the zeal package
#
0 4	* * *	root	[ -x /usr/bin/zeal_maintenance ] && /usr/bin/zeal_maintenance
