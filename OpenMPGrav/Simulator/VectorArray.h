#ifndef __VECTORARRAY_H__
#define __VECTORARRAY_H__

/*!
 * \brief ���������� ����� � ��������� ��������
 *        ��� �������� ��������, ������������ ���.
 */
struct VectorArray
{
	float* X;
	float* Y;
	float* Z;

	~VectorArray();
};

#endif
