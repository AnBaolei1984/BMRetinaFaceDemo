# BMRetinaFaceDemo
这个是在比特大陆SC5/SC5+卡上运行RetinaFace人脸检测模型的demo

1. 前提
  
    已有了bmnnsdk2-bm1684_v2.2.0的sdk，并且安装完lib和卡的驱动

2. 使用说明
 
    a)  cd bmnnsdk2-bm1684_v2.2.0/examples

    b)  git clone https://github.com/AnBaolei1984/BMRetinaFaceDemo.git

    c)  cd BMRetinaFaceDemo
  
    d)  make -f Makefile.pcie -j4
  
    e)  ./face_test face_1080p.jpg ./
        bmodel路径传到face_detection.bmodel的上一级
  
    f） 结束后可以在文件夹内看到result.jpg 的结果图片
 
