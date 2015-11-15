#include "functions.h"

NAN_METHOD(sysname) {
  struct utsname name;
  uname(&name); /* never fails :) */
  
  info.GetReturnValue().Set(Nan::New(name.sysname).ToLocalChecked());
}

NAN_METHOD(nodename) {
  struct utsname name;
  uname(&name); /* never fails :) */
  
  info.GetReturnValue().Set(Nan::New(name.nodename).ToLocalChecked());
}

NAN_METHOD(release) {
  struct utsname name;
  uname(&name); /* never fails :) */
  
  info.GetReturnValue().Set(Nan::New(name.release).ToLocalChecked());
}

NAN_METHOD(version) {
  struct utsname name;
  uname(&name); /* never fails :) */
  
  info.GetReturnValue().Set(Nan::New(name.version).ToLocalChecked());
}

NAN_METHOD(machine) {
  struct utsname name;
  uname(&name); /* never fails :) */
  
  info.GetReturnValue().Set(Nan::New(name.machine).ToLocalChecked());
}

// Wrapper Impl

Nan::Persistent<v8::Function> MyObject::constructor;

NAN_MODULE_INIT(MyObject::Init) {
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("MyObject").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  Nan::SetPrototypeMethod(tpl, "plusOne", PlusOne);

  constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());
  Nan::Set(target, Nan::New("MyObject").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

MyObject::MyObject(double value) : value_(value) {
}

MyObject::~MyObject() {
}

NAN_METHOD(MyObject::New) {
  if (info.IsConstructCall()) {
    double value = info[0]->IsUndefined() ? 0 : Nan::To<double>(info[0]).FromJust();
    MyObject *obj = new MyObject(value);
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  } else {
    const int argc = 1; 
    v8::Local<v8::Value> argv[argc] = {info[0]};
    v8::Local<v8::Function> cons = Nan::New(constructor);
    info.GetReturnValue().Set(cons->NewInstance(argc, argv));
  }
}

NAN_METHOD(MyObject::PlusOne) {
  MyObject* obj = Nan::ObjectWrap::Unwrap<MyObject>(info.This());
  obj->value_ += 1;
  info.GetReturnValue().Set(obj->value_);
}
