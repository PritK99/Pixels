# <b>Convolutional Neural Networks (CNNs)</b>

## <b>Week 1</b> 

### <b>Understanding</b> 
Week 1 gives an introduction to CNN's or Convolution Neural Networks.

### <b>Notes</b>

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

#### <b>Applying one layer of Convolution Neural Network</b>

![WhatsApp Image 2022-12-14 at 8 58 06 AM (1)](https://user-images.githubusercontent.com/103832825/207498312-c627c730-f37c-495d-a02b-67bc1980283e.jpeg)

Futther, the notations for neural network are :- 

![WhatsApp Image 2022-12-14 at 8 58 06 AM](https://user-images.githubusercontent.com/103832825/207498284-90ef0552-2eab-4f29-beea-99874489209a.jpeg)

![WhatsApp Image 2022-12-14 at 8 58 05 AM](https://user-images.githubusercontent.com/103832825/207498256-0f1b7773-29f4-4e71-800a-74b23d3c3146.jpeg)

#### <b>Types of layers in Convolution networks</b>

1) Convolution 
2) Pooling
3) Fully connected

#### <b>Pooling</b>

Pooling layers are used to reduce the dimensions of the feature maps. Thus, it reduces the number of parameters to learn and the amount of computation performed in the network.

One of the example of pooling is max-pooling.

<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20190721025744/Screenshot-2019-07-21-at-2.57.13-AM.png" alt= "Max Pooling">

The above image shows how we take a filter of 2x2 with stride of 2 and simply output the maximum number in the region where filter is applied.

This method works well with Convolutional neural networks, since the feature is always extracted. Say the feature was to locate a cat eye, so the higher numbers which represent the presence of cat-eyes are always extracted.

Also, once the stride and filter size is fixed also called as hyperparameters, there is no need of doing gradient descent here.

Another example of pooling are average pooling. This is laso used to reduce the size of input.

#### <b>Fully connected layer</b>

A fully connected layer multiplies the input by a weight matrix and then adds a bias vector.

### <b>Conclusion</b>

<img src = "https://i0.wp.com/developersbreach.com/wp-content/uploads/2020/08/cnn_banner.png?fit=1200%2C564&ssl=1" alt = "Convolutional Neural Networks" >

We prefer convolutions here, because it allows us to go for parameter sharing. Using convolutions, we do not have to train a lot of paramters. For eg. in edge detection, we simply had to tune the 9 weights of kernel and a bias parameter rather than having weight for each input pixel.

Now even if image were 64x64 or 1000x1000, we need to tune those 9 weights of filter only.

Another reason can be sparse connections.
When we get the output from a kernel, that output simply depens on the part of input where the kernel was used. For eg. if I have a 6x6 image and 3x3 kernel , the indivisual output pixels depens only on 9 of image pixels and not on all of them.

### <b>Assignments</b>

