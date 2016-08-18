#pragma once

/* ���� ����� ������������ ������.
   ������ ��������� ��������
    - aspect ration
    - �����
	- ��������� ���������

   � ��� �� ��������� ������ 
    - ���������
	- �����������
 */

#include <glm\glm.hpp>
#include <glm/gtx/transform.hpp>
#include "Transofrm.h"
#include <iostream>
#include <iomanip>

class Camera
{
public:
	Camera(float aspect_ratio, float fov, float near_clipping, float far_clipping);

	//������ ������� ������
	void SetPosition(glm::vec3 pos);
	void SetPosition(float x, float y, float z);

	//������ ����������� ������

	//������ ������� �� ������������ �����
	void SetRotationTarget(glm::vec3 target, glm::vec3 up);

	//������ ������� � ������������ �������, �������� ��������
	void SetRotationVector(glm::vec3 direction, glm::vec3 up);

	//������ ������� � ������������ �������, �������� ������
	void SetRotationAngles(float yaw, float pitch, float roll, glm::vec3 up);

	//���������� ������ �������������
	Transform GetTransform();

private:
	glm::mat4 camera_matrix, projection_matrix;
	glm::vec3 position, direction, target, up;

	void calc_camera();
};