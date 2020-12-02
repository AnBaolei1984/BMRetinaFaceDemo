# BMRetinaFaceDemo
这个是在比特大陆SC5/SC5+卡上运行RetinaFace人脸检测模型的demo

1. 前提
  已有了bmnnsdk2-bm1684_v2.2.0的sdk，并且安装完lib和卡的驱动

2. 使用说明

  1)  cd bmnnsdk2-bm1684_v2.2.0/examples
  2)  git clone https://github.com/AnBaolei1984/BMRetinaFaceDemo.git
  3)  cd BMRetinaFaceDemo
  4)  make -f Makefile.pcie -j4
  5)  ./face_test face_1080p.jpg ./
      bmodel路径传到face_detection.bmodel的上一级
  6） 结束后可以看到result.jpg 的结果图片
 
