在实际的系统开发过程中，有很多文件都是预先编译好的，比如第三方APK，so库, jar包， bin 文件，配置文件等。我们需要在系统编译时能把这些文件打包编译到系统镜像里面。我们有两种方法可以达到我们的目的： PRODUCT_COPY_FILES 和 定义 prebuilt 模块。

如果这个文件只需要预置到指定目录就可以了，那我们就可以简单的将其加入 PRODUCT_COPY_FILES 变量就行， 比如一些 bin 文件， 配置文件。
如果这个文件有其他模块编译依赖，或者这个文件需要系统签名，那我们就得定义一个预编译模块，比如一些 so 库，APK 文件， jar 包等。

PRODUCT_COPY_FILES
prebuilt
├── apk # 预置 apk 模块
├── libs # 预置库模块，so 库， jar 包等
└── vendor # PRODUCT_COPY_FILES 类型预置，按实际输出路径组织
    └── bin
        └── busybox-i686