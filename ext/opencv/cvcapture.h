/************************************************************

   cvcapture.h -

   $Author: lsxi $

   Copyright (C) 2005-2006 Masakazu Yonekura

************************************************************/
#ifndef RUBY_OPENCV_CVCAPTURE_H
#define RUBY_OPENCV_CVCAPTURE_H

#include "opencv.h"

#define __NAMESPACE_CVCAPTURE cCvCapture
#define __NAMESPACE_BEGIN_CVCAPTURE namespace __NAMESPACE_CVCAPTURE {
#define __NAMESPACE_END_CVCAPTURE }

__NAMESPACE_BEGIN_OPENCV
__NAMESPACE_BEGIN_CVCAPTURE

struct cvcapture_wrapper {
  cvcapture_wrapper(CvCapture *__capture);
  ~cvcapture_wrapper();

  void release();

  CvCapture *capture;
};

VALUE rb_class();

void define_ruby_class();

void cvcapture_free(void *ptr);
void cvcapture_release(CvCapture **ptr);
VALUE rb_open(int argc, VALUE *argv, VALUE klass);

VALUE rb_release(VALUE self);
VALUE rb_grab(VALUE self);
VALUE rb_retrieve(VALUE self);
VALUE rb_query(VALUE self);

VALUE rb_get_millisecond(VALUE self);
VALUE rb_set_millisecond(VALUE self, VALUE value);
VALUE rb_get_frames(VALUE self);
VALUE rb_set_frames(VALUE self, VALUE value);
VALUE rb_get_avi_ratio(VALUE self);
VALUE rb_set_avi_ratio(VALUE self, VALUE value);
VALUE rb_get_size(VALUE self);
VALUE rb_set_size(VALUE self, VALUE value);
VALUE rb_get_width(VALUE self);
VALUE rb_set_width(VALUE self, VALUE value);
VALUE rb_get_height(VALUE self);
VALUE rb_set_height(VALUE self, VALUE value);
VALUE rb_get_fps(VALUE self);
VALUE rb_set_fps(VALUE self, VALUE value);
VALUE rb_get_fourcc(VALUE self);
VALUE rb_get_frame_count(VALUE self);
VALUE rb_get_format(VALUE self);
VALUE rb_get_mode(VALUE self);
VALUE rb_get_brightness(VALUE self);
VALUE rb_get_contrast(VALUE self);
VALUE rb_get_saturation(VALUE self);
VALUE rb_get_hue(VALUE self);
VALUE rb_get_gain(VALUE self);
VALUE rb_get_exposure(VALUE self);
VALUE rb_get_convert_rgb(VALUE self);
VALUE rb_get_rectification(VALUE self);

__NAMESPACE_END_CVCAPTURE

inline __NAMESPACE_CVCAPTURE::cvcapture_wrapper *
CVCAPTURE_WRAPPER(VALUE object) {
  using namespace __NAMESPACE_CVCAPTURE;
  cvcapture_wrapper *ptr;
  Data_Get_Struct(object, cvcapture_wrapper, ptr);
  return ptr;
}

inline CvCapture*
CVCAPTURE(VALUE object) {
  using namespace __NAMESPACE_CVCAPTURE;
  cvcapture_wrapper * wrapper = CVCAPTURE_WRAPPER(object);
  return wrapper->capture;
}

__NAMESPACE_END_OPENCV

#endif // RUBY_OPENCV_CVCAPTURE_H
