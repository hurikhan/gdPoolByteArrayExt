#include "gdPoolByteArrayExt.h"

using namespace godot;
void GDPoolByteArrayExt::_register_methods() {
	register_method("read", &GDPoolByteArrayExt::read);
	register_method("get_u8", &GDPoolByteArrayExt::get_u8);
	register_method("get_u16", &GDPoolByteArrayExt::get_u16);
	register_method("get_u32", &GDPoolByteArrayExt::get_u32);
	register_method("get_i8", &GDPoolByteArrayExt::get_i8);
	register_method("get_i16", &GDPoolByteArrayExt::get_i16);
	register_method("get_i32", &GDPoolByteArrayExt::get_i32);
	register_method("get_f32", &GDPoolByteArrayExt::get_f32);
	register_method("get_f64", &GDPoolByteArrayExt::get_f64);
	register_method("get_vec_f32", &GDPoolByteArrayExt::get_vec_f32);
}

GDPoolByteArrayExt::GDPoolByteArrayExt() {
}

GDPoolByteArrayExt::~GDPoolByteArrayExt() {
	// add your cleanup here
}

void GDPoolByteArrayExt::_init() {
	// initialize any variables here
}

void GDPoolByteArrayExt::read(PoolByteArray p_pool) {
	pool = p_pool;
}

uint8_t GDPoolByteArrayExt::get_u8(size_t offset) {
	return pool[offset];
}

uint16_t GDPoolByteArrayExt::get_u16(size_t offset) {
	DU data;

	data.byte[0] = pool[offset];
	data.byte[1] = pool[offset + 1];

	return data.u16;
}

uint32_t GDPoolByteArrayExt::get_u32(size_t offset) {
	DU data;

	data.byte[0] = pool[offset];
	data.byte[1] = pool[offset + 1];
	data.byte[2] = pool[offset + 2];
	data.byte[3] = pool[offset + 3];

	return data.u32;
}

int8_t GDPoolByteArrayExt::get_i8(size_t offset) {
	return pool[offset];
}

int16_t GDPoolByteArrayExt::get_i16(size_t offset) {
	DU data;

	data.byte[0] = pool[offset];
	data.byte[1] = pool[offset + 1];

	return data.u16;
}

int32_t GDPoolByteArrayExt::get_i32(size_t offset) {
	DU data;

	data.byte[0] = pool[offset];
	data.byte[1] = pool[offset + 1];
	data.byte[2] = pool[offset + 2];
	data.byte[3] = pool[offset + 3];

	return data.u32;
}

float GDPoolByteArrayExt::get_f32(size_t offset) {
	DU data;

	data.byte[0] = pool[offset];
	data.byte[1] = pool[offset + 1];
	data.byte[2] = pool[offset + 2];
	data.byte[3] = pool[offset + 3];

	return float(data.f32);
}

float GDPoolByteArrayExt::get_f64(size_t offset) {
	DU data;

	data.byte[0] = pool[offset];
	data.byte[1] = pool[offset + 1];
	data.byte[2] = pool[offset + 2];
	data.byte[3] = pool[offset + 3];
	data.byte[4] = pool[offset + 4];
	data.byte[5] = pool[offset + 5];
	data.byte[6] = pool[offset + 6];
	data.byte[7] = pool[offset + 7];

	return float(data.f64);
}

Vector3 GDPoolByteArrayExt::get_vec_f32(size_t offset) {

	float_t x, y, z;

	x = get_f32(offset + 0);
	y = get_f32(offset + 4);
	z = get_f32(offset + 8);

	Vector3 v;

	v.x = x;
	v.y = y;
	v.z = z;

	return v;
}
