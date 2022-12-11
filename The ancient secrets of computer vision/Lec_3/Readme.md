# Lec_3

This lecture introduces us to the ways images are represented in computer, the way they are aquired from the sensors,

## Notes 

### Image
The camera that we use, is made of many sensors. The problem with these sensor here is that it is very good at detecting the <b> intensity of light </b> and NOT the colour of light. Thus, each photosite is colorblind. It only keeps track of the total intensity of the light that strikes its surface. 

![image](https://user-images.githubusercontent.com/103832825/206824216-12ece07f-daa8-42d9-9b4d-f8656f7ebf0f.png)

This is what really happens with the sensor, that they just absorb intensity of given light without any sense of colour. This is what we need for grayscale, just the intensity of light at each point. But for RGB, we need sense of colour.

In order to get a full color image, most sensors use filtering to look at the light in its three primary colors. 

![image](https://user-images.githubusercontent.com/103832825/206824281-212bfd5f-bb66-430e-8f6a-a84368fac012.png)

Now assume a Red filter over the first sensor, green over the second sensor and blue over third sensor.
Thus what the sensors now give is the R,G and B intensities which is a sense of colour. Now for actual image, you can take the referance of nearby pixels to conclude what amout of red, green and blue is actuallt present in that pixel of image. This process is called Demosaicing.

Imagine the scenario of this filter given these readings

R  G          108  220
      ----->
G  B          200  128

Now the pixel in place of that R in real image would have some sense of amount of green and blue colour it might have looking at its neighbours. This is how it calculates values of R, G and B for that pixel.
This is the bayer filter :-

![1200px-Bayer_pattern_on_sensor svg](https://user-images.githubusercontent.com/103832825/206824663-d53bde0e-be52-4e82-804e-76206de91e3a.png)
![Bayer_pattern_on_sensor_profile svg](https://user-images.githubusercontent.com/103832825/206824687-e10e8f38-bbab-4bf2-bd3a-bebf3c8231cf.png)

In bayer filter, there are two green filters for each red and blue filter because our eyes is more sensitive to the green colour, which is luminanace rather than blue and red, which is chrominance.

Bayer filter is thus an actual physical thing present in front of our camera !

This <a href = "https://www.youtube.com/watch?v=LWxu4rkZBLw&t=355s" alt = "Computerphile video on capturing digital images"> video</a> very nicely explains how the images is captured, filtered etc.

Now, the way image is represented is a tensor i.e. a 2-D array with higher dimension.

![image](https://user-images.githubusercontent.com/103832825/206825749-123e739f-b75c-4970-85a8-b8ec5284ac9f.png)

The indexing starts from the left-topmost pixel. Essentially, the standard Y-axis has been flipped upside down.
So, (x , y) here would mean <b>xth column</b> and <b>yth row</b>. It is ( col , row ) format. Thus ( 5 , 7 ) would really mean 5th column and 7th row.

![image](https://user-images.githubusercontent.com/103832825/206883804-fb2b645c-6ecd-41ae-b10e-b3261cafb311.png)

This image however, is stored as a linear array in memory. For given (x , y , c) , where x represents column, represents rows and c represents channel we can address pixel in the image using :-

      x + (y * im.w) + (c*im.w * im.h)

where im.c , im.h represent the total width and height of image respectively

### Colour spaces other than RGB (HSV)

Hues are the three primary colors (red, blue, and yellow). So when you ask what is hue, you mean is it red, blue or green ? 
Value is simply relative lightness and darkness of colour.
Saturation is the intensity of colour 



