https://source.android.com/docs/core/ota/sign_builds

默认的证书类型有
testkey
platform
shared
media
networkstack
这些证书在
croot/build/make/target/product/security目录下

我们自定义的证书，放在
device/cfm880/pure/security/appKey
那么使用的就是device/cfm880/pure/security/appKey.{x509.pem, pk8}来签名apk，这种只能使用私钥，不能使用密码来保护
这是证书报存的地方

生成这公钥和私钥
Manually generating keys
```shell
openssl genrsa -3 -out temp.pem 2048
openssl req -new -x509 -key temp.pem -out releasekey.x509.pem -days 10000 -subj '/C=CN/ST=Beijing/L=Chaoyang/O=CFM880, Inc./OU=CFM880 Mobility/CN=CFM880/emailAddress=chengfangming1993@gmail.com'
openssl pkcs8 -in temp.pem -topk8 -outform DER -out releasekey.pk8 -nocrypt
shred --remove temp.pem
```
就得到了releasekey

