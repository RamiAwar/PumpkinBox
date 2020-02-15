#pragma once

#include "OpsCore/Input.h"

namespace oc {

	class winInput : public Input {

	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		// Inherited via Input
		virtual bool IsMouseButtonPressedImpl(int keycode) override;
		virtual bool GetMouseXImpl() override;
		virtual bool GetMouseYImpl() override;
		virtual std::pair<float, float> GetMousePosImpl() override;
	};
}