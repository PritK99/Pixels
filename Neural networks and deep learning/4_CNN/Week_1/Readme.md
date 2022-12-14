# Neural networks and deep learning

## Week 1 

### Understanding 
Week 1 gives an introduction to CNN's or Convolution Neural Networks.

### Notes 

#### <b>Introduction</b>
Convolution (in computer vision) is basically moving a weighted kernel or filter over image and generating an output image.
The fine tuning of the weights is done by implementing neural networks so that we dont have to mannually work on it.

#### <b>Edge detection</b>
For edge detecion we use the kernel :-

![image](https://user-images.githubusercontent.com/103832825/207421496-31b844a0-8dd2-49c3-811f-13d55496a8b3.png)

Here, the first image represents vertical edge detetction while second is for horizontal.

But there are several otber filters which may perform better edge detection for the given set of images. Sobel filter is one such example.

<img src = "https://i0.wp.com/www.adeveloperdiary.com/wp-content/uploads/2019/05/How-to-implement-Sobel-edge-detection-using-Python-from-scratch-adeveloperdiary.com-sobel-sobel-operator.jpg?resize=744%2C356" alt = "Image of sobel filter">

Thus, rather than tuning the weights ourselves, we use neural networks which gives most optimized weights to kernel.

#### <b>Padding</b>

When we apply a fxf Filter over nxn image, we get an output which is (n-f+1)*(n-f+1).
Thus in this case the edge pixels dont play much role in output and the size keeps on shrinking. This is because there is no space at edges to apply filter on.

<img src = "https://images.deepai.org/django-summernote/2019-05-27/c3f24854-5584-4feb-81d7-3bcc5800a689.png" alt = "Padding">

Hence we do padding, to give equal importance to edge pixels too and not reduce the image size every time it passes through a layer of convolution.

Thus there are two types of convolutions :-

1) Valid Convolutions : Without padding , size decreases.
2) Same Convolutions : With padding , size remains the same.

The value of Padding for same convolutions is (f-1/2). This works usually for f = odd, and generally all filters are odd x odd kernels.
Also, being odd x odd allows them to focus on central pixel too.

#### <b>Stride Convololution</b>

Stride convolutions refers to the the step size while convolution. Generally, we move the kernel one row by row and one column by column. This is a stride = 1.
Incase of stride = 2 , we directly jump our kernel by two rows or 2 columns.

#### <b>Convolution over volume</b>

Instead of just applying convolutions on 2D images, we can also apply convolutions on volumes. For eg. If we have a RGB image, it has dimensions (width , height , channel) say 6x6x3. The in that case our filter is also supposed to have 3 channels, say 3x3x3 is our filter.

The final output is a 4x4 2D image.

![image](https://user-images.githubusercontent.com/103832825/207489294-bd43cd1d-247f-4f57-9a62-8a726cf36f40.png)

Apart from this, you can apply multiple filters, say we applied 2 filters, horizontal edge and vertical edge. Then in that case our final output will be 4x4x2 image, where that 2 is because of applying 2 filters on same volume.

