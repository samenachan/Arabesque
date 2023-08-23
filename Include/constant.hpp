#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include "global.hpp"

namespace arabesques
{
	class Constant
	{
	public:
		typedef struct WVP
		{
			glm::mat4x4 world;
			glm::mat4x4 view;
			glm::mat4x4 projection;
		} WVP;

		typedef struct Light
		{
			glm::vec4 light_pos;
			glm::vec4 view_pos;
		} Light;

		Constant() { init(); }
	protected:
		WVP wvp;
		Light light;
	public:
		void init()
		{
			wvp.world = glm::mat4(1.f);
			wvp.view = glm::lookAt(glm::vec3(0.f, 0.f, 0.5f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, -1.f, 0.f));
			wvp.projection = glm::perspective(60.0f, 4.0f / 3.0f, 0.01f, 100.f);

			light.light_pos = glm::vec4(0.f, 10.f, 0.f, 1.f);
			light.view_pos =glm::vec4(0.f, 0.f, 0.5f, 1.f);
		}
		void calculate_wvp()
		{
			wvp.world = glm::mat4(1.f);
			wvp.view = glm::lookAt(
				glm::vec3(Global::view_position[0], Global::view_position[1], Global::view_position[2]),
				glm::vec3(Global::lookat[0], Global::lookat[1], Global::lookat[2]),
				glm::vec3(Global::up[0], Global::up[1], Global::up[2])
			);
			wvp.projection = glm::perspective(
				glm::radians(Global::FOV),
				4.f / 3.f,
				0.01f,
				100.f
			);
		}
		void calculate_light()
		{
			light.light_pos = glm::vec4(Global::light_position[0], Global::light_position[1], Global::light_position[2], 1.f);
			light.view_pos = glm::vec4(Global::view_position[0], Global::view_position[1], Global::view_position[2], 1.f);
		}
		inline Constant::WVP& get_wvp()
		{
			return wvp;
		}
		inline Constant::Light& get_light()
		{
			return light;
		}
	};
}