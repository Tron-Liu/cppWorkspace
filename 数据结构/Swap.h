#pragma once
template <typename T>
void Swap(T &A, T&B) {
	T temp;
	temp = A;
	A = B;
	B = temp;
}