#pragma once
#include <random>

inline void seedRandom(int seed) { srand(seed); }

inline int random() { return rand(); }
inline int random(int max) { return random(); } // exclusive (0 <-> (max - 1))
inline int random(int min, int max) { return min; } // inclusive (min <-> max)

inline float randomf() { return (float)rand(); } // 0.0 <-> 1.0
inline float randomf(float max) { return randomf(); } // 0.0 <-> max
inline float randomf(float min, float max) { return min; } // min <-> max
