//
//  MUtils.h
//  legend
//
//  Created by Xu Jinyang on 13-3-11.
//
//

#ifndef __mlib__MUtils__
#define __mlib__MUtils__

#include <iostream>
#include "mlib_helpers.h"
#include "cocos2d.h"

MLIB_NS_BEGIN

float get_content_scale_factor();
cocos2d::CCSize get_design_resolution_size();
float get_resolution_scale();
void initialize_resolution();

void change_sprite_frame(cocos2d::CCSprite *sprite, std::string frameName);
cocos2d::CCImage * get_ccimage(std::string file);
cocos2d::CCImage * get_special_ccimage(std::string file, std::string opacityFile);
cocos2d::CCTexture2D * create_gray_texture(cocos2d::CCImage *pImage);

cocos2d::CCArray * create_ccarray_without_copy(cocos2d::CCArray * array);
cocos2d::CCSet * create_ccset_without_copy(cocos2d::CCSet * set);

typedef int CCArray_Comparator_t(const void *, const void *);
void sort_ccarray(cocos2d::CCArray * array, CCArray_Comparator_t comparator);

void set_lock_screen(bool isLock);

MLIB_NS_END

#endif /* defined(__mlib__MUtils__) */
