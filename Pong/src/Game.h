#include <OpsCore.h>
#include "imgui.h"


class Game : public oc::Layer {

public:

	Game();

	void OnAttach() override;
	void OnDetach() override;
	void OnUpdate(oc::Timestep ds) override;
	void OnEvent(oc::Event& event) override;
	virtual void OnImGuiRender() override;

private:

	oc::ShaderLibrary m_ShaderLibrary;

	oc::OrthographicCameraController m_CameraController;

	oc::Ref<oc::Texture2D> checkerboard_texture;
	oc::Ref<oc::Texture2D> mushroom_texture;

	std::string m_CurrentShader;
	std::string m_CheckerboardPath = "assets/textures/checkerboard.png";
	std::string m_MushroomPath = "assets/textures/super.png";

	// Tracked stats
	static float m_FPS;
	static int fps_counter;

};