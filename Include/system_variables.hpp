#pragma once
#include <iostream>

namespace albedo {
	class System {
	public:
		static float bg_color[4];

		static float light_position[3];
		static float light_ambient[4];
		static float light_intensity;
		static bool	 is_enabled_shadow_mapping;
		static float shadow_mapping_bias;
		static bool	 is_enabled_msaa;
		static bool	 is_enabled_postprocess;
		static bool	 is_enabled_skydome;
	};

	float System::bg_color[4] = {0.725f, 0.788f, 0.788f, 1.f};

	float System::light_position[3]			= {6.f, 2.f, 8.0f};
	float System::light_ambient[4]			= {0.1f, 0.1f, 0.1f, 1.f};
	float System::light_intensity			= 1.f;
	bool  System::is_enabled_shadow_mapping = true;
	float System::shadow_mapping_bias		= 0.00015f;
	bool  System::is_enabled_msaa			= true;
	bool  System::is_enabled_postprocess	= false;
	bool  System::is_enabled_skydome		= true;
} // namespace albedo