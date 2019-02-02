//
//  imgproc.hpp
//  _image
//
//  Created by 唐宇阳 on 2019/01/29.
//  Copyright © 2019 唐宇阳. All rights reserved.
//

#ifndef IMGPROC_HPP
#define IMGPROC_HPP

#include "image.hpp"

//seperate 3-channel image to 1-channel
//void split(const img::Image &img, img::Image &channe0, img::Image &channel1, img::Image &channel2);

//contrast stretch
void stretch(img::Image &img, int min, int max);

#endif /* IMGPROC_HPP */
