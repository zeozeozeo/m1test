#include <Geode/Geode.hpp>
#include <Geode/modify/EffectGameObject.hpp>
#include <cmath>

using namespace geode::prelude;

inline constexpr bool nearlyEqual(float a, float b) {
	return fabs(a - b) < 0.0001f;
}

class $modify(EffectGameObject) {
	void triggerObject(GJBaseGameLayer* p0, int p1, const gd::vector<int>* p2) {
		EffectGameObject::triggerObject(p0, p1, p2);
		uintptr_t base = reinterpret_cast<uintptr_t>(this);
		for (uintptr_t ptr = base; ptr < base + 0x2000; ptr += sizeof(float)) {
			auto v = *reinterpret_cast<float*>(ptr);
			if (nearlyEqual(v, 5.f)) {
				log::info("------- OFFSET: 0x{:x}", ptr - base);
			}
		}
	}
};
