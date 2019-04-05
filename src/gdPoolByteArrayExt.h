#ifndef GDPOOLBYTEARRAY_EXT_H
#define GDPOOLBYTEARRAY_EXT_H

#include <Godot.hpp>
#include <PoolArrays.hpp>
#include <Reference.hpp>
//#include <cstdint>

namespace godot {

class GDPoolByteArrayExt : public Reference {
	GODOT_CLASS(GDPoolByteArrayExt, Reference)

private:
	PoolByteArray pool;

	union DU {
		uint8_t u8;
		uint16_t u16;
		uint32_t u32;

		int8_t i8;
		int16_t i16;
		int32_t i32;

		float_t f32;
		double_t f64;

		std::uint8_t byte[8];
	};

public:
	static void _register_methods();

	GDPoolByteArrayExt();
	~GDPoolByteArrayExt();

	void _init(); // our initializer called by Godot

	void read(PoolByteArray p_pool);
	uint8_t get_u8(size_t offset);
	uint16_t get_u16(size_t offset);
	uint32_t get_u32(size_t offset);

	int8_t get_i8(size_t offset);
	int16_t get_i16(size_t offset);
	int32_t get_i32(size_t offset);

	float get_f32(size_t offset);
	float get_f64(size_t offset);

	Vector3 get_vec_f32(size_t offset);
};

} // namespace godot

#endif
