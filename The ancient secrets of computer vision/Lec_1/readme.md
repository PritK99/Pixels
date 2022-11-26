# Lec_1

## Notes 

### Introduction 
Computer vision can essentially be divided into 
1) Low level computer vision
2) Mid level computer vision
3) High level computer vision 

### Low level computer vision
This is essentially playing with pixel values
1) Re-sizing : There are several methods to do resizing such as :-
  1) Nearest neighbour : faster results , but bad quality
  2) Bilinear interpolation : slower results , but high quality 
2) Grayscale : The entire image is converted to grayscale which ranges from 0 - 255. 
3) Saturation : colourfullness
4) Hue
5) Edge detection 
6) Oriented gradient : This is edge detection + orientation
7) Image segmentation : eg. removing the background from photo


### Mid level computer vision
This is essentially playing with pixel and not worried about internal pixel values
1) Photo stiching : To take two photos and stitch them with each other. Eg. the youtube speherical videos 
2) Multi - view stereo : This invloves looking at the photo shaking back and forth looking 3D 
3) Range finding OR LIDAR 
4) Optical flow : This is essentially tracking the moving pixels. This can also be used for object tracking.
5) Time lapse

It is related to connecting images to images OR images to real world such as stiching 2 images, depth 3D view etc
It also deals with time lapses and optical flow

### High level computer vision 
A lot of things such as image classification , YOLO detection , identifications etc. come under High level computer vision
1) Object identification
2) Object tagging
3) Object detection
4) semantic segmentation : it is object tagging but down to pixel level
5) game playing
6) Image retrival
These methods are often used in robots etc.

High level vision is not only limited to extracting semantics out of an image, but also deals with creating an image out of the semantics.
for eg. given a vector, computer can form randomly generated images from it which it has never seen before.

### Conclusion 
This lecture introduces us to computer vision, classifies computer vision into three tires and gives explaination and applications of each.
