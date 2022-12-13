# Neural networks and deep learning

## Week 1 

### Understanding 
Week 1 gives an introduction to CNN's or Convolution Neural Networks.

### Notes 

Convolution (in computer vision) is basically moving a weighted kernel or filter over image and generating an output image.
The fine tuning of the weights is done by implementing neural networks so that we dont have to mannually work on it.

1) Edge Detection :-

For edge detecion we use the kernel :-

![image](https://user-images.githubusercontent.com/103832825/207421496-31b844a0-8dd2-49c3-811f-13d55496a8b3.png)

Here, the first image represents vertical edge detetction while second is for horizontal.

But there are several otber filters which may perform better edge detection for the given set of images. Sobel filter is one such example.

<img src = "https://i0.wp.com/www.adeveloperdiary.com/wp-content/uploads/2019/05/How-to-implement-Sobel-edge-detection-using-Python-from-scratch-adeveloperdiary.com-sobel-sobel-operator.jpg?resize=744%2C356" alt = "Image of sobel filter">

Thus, rather than tuning the weights ourselves, we use neural networks which gives most optimized weights to kernel.
