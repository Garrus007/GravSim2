#ifndef __GRAVSIM_H__
#define __GRAVSIM_H__

#include "Points.h"
#include <omp.h>
#include <cstdlib>
#include <glm/glm.hpp>

/*!
 * \brief ��������� ���������� - ������� ������ n-���
 */
class GravSim
{
public:

	GravSim();
	GravSim(int count, glm::vec3 center, glm::vec3 radius);
	~GravSim();

	void Init(int count, glm::vec3 center, glm::vec3 radius);

	void CalcFrameSingleThread(float dt);
	Points* GetPoints();

private:

	Points points;

	//������� ������ ��������� �������
	void init_vector(VectorArray * array, int count);

	//������� ������ Float  ��������� �������
	void init_array(float** arr, int count, float default=0);

	//������ ��������� �������� ��� ��������� ������� � �������� ������� �� (0,0,0)
	void set_random_values(VectorArray* values, glm::vec3 radius, glm::vec3 center, int count);

};

#endif