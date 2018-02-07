#!/usr/bin/env bash
#

echo "starting the DoSSiER connection test"

echo "nslookup g4devel : "
/usr/bin/nslookup g4devel

echo "traceroute g4devel : "
/bin/traceroute g4devel

/g4/yarba_j/art-g4-apps-work/DBConect/dbconnect1

echo "end of DoSSiER connection test"



