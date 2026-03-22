Max Antrian = 5

Input no polisi divalidasikan agar range nomornya diantara 3000-6999.

//kode daerah [1-2 digit]:
cth : B, F, D, dsb

//no : 3000 - 6999 = motor
cth : 5432 ok, 7000 = bus (not ok)

//seri umum [2-3 digit]	: 
[Area,jenis kendaraan,dan kode pembeda] 
cth : BNS, KPK, DPR

http://id.wikipedia.org/wiki/Tanda_nomor_kendaraan_bermotor

Bisa menggunakan 
sscanf(const char *, [Format specifier]...)

cth :
char tes[50]={"B 1 NUS"};
char kode[10], seri[10];
int no;

sscanf(tes, "%s %d %s", &kode, &no, &seri);
// no = 1 (int);

ongkos cuci :
1. regular = 10.000
2. vip = 15.000