#pragma once
#include <stdint.h>
#include <cstddef>

template <size_t N = 10>
class MedianFilter {
	private:
		static_assert(N > 0, "[MedianFilter<N>]: N must be greater than 0");
		static_assert(N <= 255, "[MedianFilter<N>]: N is too big");


		float ring[N] = {};
		size_t index = 0;
		size_t filled = 0;

	public:
		float update(float newVal) {
			ring[index] = newVal;
			index = (index + 1) % N;

			if (filled < N) {
				filled++;
			}

			float temp[N];
			for (size_t i = 0; i < filled; i++) {
				temp[i] = ring[i];
			}

			for (size_t i = 0; i < filled; i++) {
				for (size_t j = i + 1; j < filled; j++) {
			    if (temp[j] < temp[i]) {
		        float t = temp[i];
		        temp[i] = temp[j];
		        temp[j] = t;
			    }
				}
			}

			if ((filled % 2) == 0) {
				return (temp[filled / 2 - 1] + temp[filled / 2]) * 0.5f;
			}

			return temp[filled / 2];
		}
};
