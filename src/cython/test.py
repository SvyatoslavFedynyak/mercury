import json
from binascii import unhexlify

from mercury import *

b64_cert = 'MIIJRDCCCCygAwIBAgIRAO7eZWDNNcCvAgAAAABZcbcwDQYJKoZIhvcNAQELBQAwQjELMAkGA1UEBhMCVVMxHjAcBgNVBAoTFUdvb2dsZSBUcnVzdCBTZXJ2aWNlczETMBEGA1UEAxMKR1RTIENBIDFPMTAeFw0yMDAyMTIxMTQ3MTFaFw0yMDA1MDYxMTQ3MTFaMGYxCzAJBgNVBAYTAlVTMRMwEQYDVQQIEwpDYWxpZm9ybmlhMRYwFAYDVQQHEw1Nb3VudGFpbiBWaWV3MRMwEQYDVQQKEwpHb29nbGUgTExDMRUwEwYDVQQDDAwqLmdvb2dsZS5jb20wWTATBgcqhkjOPQIBBggqhkjOPQMBBwNCAATKjE9IuwUMNbIbCmiOS1XWI2yPFLanStLIADumajnPmHrED+4/bPKa3HXecM4hPVHL8OgqwVYWveZsS6OdF9Pqo4IG2jCCBtYwDgYDVR0PAQH/BAQDAgeAMBMGA1UdJQQMMAoGCCsGAQUFBwMBMAwGA1UdEwEB/wQCMAAwHQYDVR0OBBYEFCRtN1AKArkz3KlGMpfhLYkaPFkYMB8GA1UdIwQYMBaAFJjR+G4Q68+b7GCfGJAboOt9Cf0rMGQGCCsGAQUFBwEBBFgwVjAnBggrBgEFBQcwAYYbaHR0cDovL29jc3AucGtpLmdvb2cvZ3RzMW8xMCsGCCsGAQUFBzAChh9odHRwOi8vcGtpLmdvb2cvZ3NyMi9HVFMxTzEuY3J0MIIEnQYDVR0RBIIElDCCBJCCDCouZ29vZ2xlLmNvbYINKi5hbmRyb2lkLmNvbYIWKi5hcHBlbmdpbmUuZ29vZ2xlLmNvbYISKi5jbG91ZC5nb29nbGUuY29tghgqLmNyb3dkc291cmNlLmdvb2dsZS5jb22CBiouZy5jb4IOKi5nY3AuZ3Z0Mi5jb22CESouZ2NwY2RuLmd2dDEuY29tggoqLmdncGh0LmNugg4qLmdrZWNuYXBwcy5jboIWKi5nb29nbGUtYW5hbHl0aWNzLmNvbYILKi5nb29nbGUuY2GCCyouZ29vZ2xlLmNsgg4qLmdvb2dsZS5jby5pboIOKi5nb29nbGUuY28uanCCDiouZ29vZ2xlLmNvLnVrgg8qLmdvb2dsZS5jb20uYXKCDyouZ29vZ2xlLmNvbS5hdYIPKi5nb29nbGUuY29tLmJygg8qLmdvb2dsZS5jb20uY2+CDyouZ29vZ2xlLmNvbS5teIIPKi5nb29nbGUuY29tLnRygg8qLmdvb2dsZS5jb20udm6CCyouZ29vZ2xlLmRlggsqLmdvb2dsZS5lc4ILKi5nb29nbGUuZnKCCyouZ29vZ2xlLmh1ggsqLmdvb2dsZS5pdIILKi5nb29nbGUubmyCCyouZ29vZ2xlLnBsggsqLmdvb2dsZS5wdIISKi5nb29nbGVhZGFwaXMuY29tgg8qLmdvb2dsZWFwaXMuY26CESouZ29vZ2xlY25hcHBzLmNughQqLmdvb2dsZWNvbW1lcmNlLmNvbYIRKi5nb29nbGV2aWRlby5jb22CDCouZ3N0YXRpYy5jboINKi5nc3RhdGljLmNvbYISKi5nc3RhdGljY25hcHBzLmNuggoqLmd2dDEuY29tggoqLmd2dDIuY29tghQqLm1ldHJpYy5nc3RhdGljLmNvbYIMKi51cmNoaW4uY29tghAqLnVybC5nb29nbGUuY29tghMqLndlYXIuZ2tlY25hcHBzLmNughYqLnlvdXR1YmUtbm9jb29raWUuY29tgg0qLnlvdXR1YmUuY29tghYqLnlvdXR1YmVlZHVjYXRpb24uY29tghEqLnlvdXR1YmVraWRzLmNvbYIHKi55dC5iZYILKi55dGltZy5jb22CGmFuZHJvaWQuY2xpZW50cy5nb29nbGUuY29tggthbmRyb2lkLmNvbYIbZGV2ZWxvcGVyLmFuZHJvaWQuZ29vZ2xlLmNughxkZXZlbG9wZXJzLmFuZHJvaWQuZ29vZ2xlLmNuggRnLmNvgghnZ3BodC5jboIMZ2tlY25hcHBzLmNuggZnb28uZ2yCFGdvb2dsZS1hbmFseXRpY3MuY29tggpnb29nbGUuY29tgg9nb29nbGVjbmFwcHMuY26CEmdvb2dsZWNvbW1lcmNlLmNvbYIYc291cmNlLmFuZHJvaWQuZ29vZ2xlLmNuggp1cmNoaW4uY29tggp3d3cuZ29vLmdsggh5b3V0dS5iZYILeW91dHViZS5jb22CFHlvdXR1YmVlZHVjYXRpb24uY29tgg95b3V0dWJla2lkcy5jb22CBXl0LmJlMCEGA1UdIAQaMBgwCAYGZ4EMAQICMAwGCisGAQQB1nkCBQMwLwYDVR0fBCgwJjAk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'


print(parse_cert(b64_cert))

b64_dns = '1e2BgAABAAAAAQAABGxpdmUGZ2l0aHViA2NvbQAAHAABwBEABgABAAABzQBIB25zLTE3MDcJYXdzZG5zLTIxAmNvAnVrABFhd3NkbnMtaG9zdG1hc3RlcgZhbWF6b27AGAAAAAEAABwgAAADhAASdQAAAVGA'

print(parse_dns(b64_dns))

pkts = [
    b'5254001235020800273a230d08004500022d8437400040065a730a00020f0df9401980cc01bb5b91e19f0634de025018faf05c4000001603010200010001fc03030d4e266cf66416689ded443b58d2b12bb2f53e8a3207148e3c8f2be2476cbd242067b5db473da1b71fbca9ed288052032ee0d5139dcfd6ea78b4436e509703c0e40024130113031302c02bc02fcca9cca8c02cc030c00ac009c013c014009c009d002f0035000a0100018f000000280026000023636f6e74656e742d7369676e61747572652d322e63646e2e6d6f7a696c6c612e6e657400170000ff01000100000a000e000c001d00170018001901000101000b00020100002300000010000e000c02683208687474702f312e310005000501000000000033006b0069001d00202934574bdc2a34d7f13e992529e04799e9a0ee824e0f714d5aa5d473995a390600170041046a068ede9cae5be42d0f6eb5b9de6fea0c66f9190b525dfe80efbdaa670c2c4f3a98cb9f0b4ee9ff5dc20365e31ea0f7ff524dd3789fac2066c4bb575bbde2db002b00050403040303000d0018001604030503060308040805080604010501060102030201002d00020101001c000240010015007f00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000',
    b'5254001235020800273a230d08004500003c8435400040065c660a00020f0df9401980cc01bb5b91e19e00000000a002faf05a4f0000020405b40402080a1e4e2f0e0000000001030307',
    b'5254001235020800277e0ed808004500022d3f4e40004006eb9d0a00020f681299bea9dc01bbab504e76e433ec025018faf00fff00001603010200010001fc0303a552de5bcc6193c398b5cce45fa3e4235de843efac1e180855b48ef63967886120e54765539b1bab802a98846fde9bf573b5f237e8cc0bad139d383ded1ae235130022130213011303cca8003cc02b009cc027009dcca9c02c0035c013c014000a002fc0090100019100230000000a000a0008001d001700180019000d00140012020106010804080605010503040308050401000b00020100002b0009080304030303020301000500050100000000ff01000100001500fc000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000003300260024001d0020198c3c99abe37fca8a705cbc2604f15f350de1c099212cbdc4a723487081730a0010000e000c02683208687474702f312e3100120000002d00020101',
    b'02020202020204040404040408004500015600014000800611110a00000168f42ac2c03401bb000000010000000150180204111100001603010129010001250303ec3d885ef33e9fd085e351daaf5a6f3cbff3dd21e62688104e5769cc5bc035310000300a0a130113021303c02cc02bcca9c030c02fcca8c024c023c00ac009c028c027c014c013009d009c003d003c0035002f010000cc0a0a000838db9ccede65b23900000014001200000f6170692e747769747465722e636f6d00170000ff01000100000a000c000a0a0a001d001700180019000b000201000010000b000908687474702f312e31000500050100000000000d0018001604030804040105030203080508050501080606010201001200000033002b00298a8a000100001d002087144e5633f09ec26a05d5939d35b56f8bc9176914d230fb33629c73824b3f32002d00020101002b0007060a0a03040303001b00030200010a0a0001000015000100',
    b'0202020202020404040404040800450000fd00014000800611110a000001ad247f10c02e01bb0000000100000001501802041111000016030100d0010000cc030342f2b9bd662517abb9bbbf7e19b34296f259b8b836d602fe1040d83b1f590c6b0000200a0a130113021303c02bc02fc02cc030cca9cca8c013c014009c009d002f00350100008300000023002100001e75637368636c746f6f6c2e636c6f7564617070732e636973636f2e636f6d002300000010000b000908687474702f312e3100170000000a00080006001d00170018000b00020100000d00120010080606010805050305010804040304010005000501000000000a0a0000002b000706030303020301ff01000100',
    b'525400123502080027208c4508004510008c1e5040004006b2d80a00020f0a1f5306ea240016a5b9a39b05221b4b5018ffff69b20000b2ed11be42a165f7f062fad4d254e8c47c112d82d748fa2c4801c372ff614e1490eefb2f75753976d98a6ddfe40652abc9311512f576969aba30f993aad290dec3f61cc8fefc7b87f7f8cdd9c88114fb2abaf0c484dcc86d94e40f39c51cc23f63a5a47b',
]

try:
    libmerc = Mercury(do_analysis=True, resources=b"test/data/resources-test.tgz")
except:
    libmerc = Mercury(do_analysis=True, resources=b"../../test/data/resources-test.tgz")

#result = libmerc.perform_analysis('(0303)(0a0a130313011302cca9cca8c02bc02fc02cc030c013c014009c009d002f0035)((0a0a0000)(0000)(0017)(ff01)(000a000a00080a0a001d00170018)(000b00020100)(0023)(0010000e000c02683208687474702f312e31)(000500050100000000)(000d0012001004030804040105030805050108060601)(0012)(0033)(002d00020101)(002b000b0a0a0a0304030303020301)(001b0003020002)(0a0a000100)(0015))','www.google.com','8.8.8.8',443)
#print(json.dumps(result, indent=2))

libmerc.mercury_init()
for pkt in pkts:
    print("\nTesting packet:", pkt.decode('utf-8'))
    pkt2 = unhexlify(pkt)
    result = libmerc.analyze_packet(pkt2)
    print(json.dumps(result, indent=2))
    result = libmerc.get_mercury_json(pkt2)
    print(result)
libmerc.mercury_finalize()
