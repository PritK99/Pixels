from uwimg import *

# 1. Getting and setting pixels
im = load_image("data/dog.jpg")
for row in range(im.h):
    for col in range(im.w):
        set_pixel(im, col, row, 0, 0)
save_image(im, "output/dog_no_red")

im = load_image("data/rgb.png")
for row in range(im.h):
    for col in range(im.w):
        set_pixel(im, col, row, 2, 0)
save_image(im, "output/rgb_no_blue")

# 3. Grayscale image
im = load_image("data/colorbar.png")
graybar = rgb_to_grayscale(im)
save_image(graybar, "output/graybar")

im = load_image("data/rgb.png")
grayrgb = rgb_to_grayscale(im)
save_image(grayrgb, "output/grayrgb")

# 4. Shift Image
im = load_image("data/dog.jpg")
shift_image(im, 0, .4)
shift_image(im, 1, .4)
shift_image(im, 2, .4)
# we call this overflow because the pixel value might have exceeded 1 giving this weird patterns
save_image(im, "output/Dog_overflow")

# 5. Clamp Image
clamp_image(im)
save_image(im, "output/doglight_fixed")

# 4. Shift Image
im = load_image("data/rgb.png")
shift_image(im, 0, .4)
shift_image(im, 1, .4)
shift_image(im, 2, .4)

save_image(im, "output/RGB_overflow")

# 5. Clamp Image
clamp_image(im)
save_image(im, "output/RGB_fixed")

# 6-7. Colorspace and saturation
im = load_image("data/dog.jpg")
rgb_to_hsv(im)
save_image(im, "output/HSV_dog")
shift_image(im, 1, .2)
clamp_image(im)
hsv_to_rgb(im)
save_image(im, "output/dog_saturated")


