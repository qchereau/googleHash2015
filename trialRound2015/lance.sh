#! /bin/bash


sed -e '1d' -e '81aSERV' dc.in > dc.in2

 ./lit_tableau < dc.in2  > dc_serv_cap 2> dc_serv_util

sort -rg dc_serv_cap > dc_serv_cap_ord
sort -rg  dc_serv_util > dc_serv_util_ord

cp dc.in2 dc.in3
echo 'CAP' >> dc.in3
cat dc_serv_cap_ord >> dc.in3 
echo 'UTIL' >> dc.in3
cat dc_serv_util_ord >> dc.in3

./range_servers < dc.in3 > res1.txt

