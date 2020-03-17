#include "ocpch.h"

#include "OpsCore/Core/Input.h"
#include "OpsCore/Core/Application.h"

#include "OpsCore/Renderer/Renderer.h"
#include "OpsCore/Renderer/RenderCommand.h"

#include "OpsCore/Core/SceneStateMachine.h"

#include <GLFW/glfw3.h>

namespace oc {

	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)


	Application* Application::s_Instance = nullptr;

	Application::Application() 
	{

		OC_ASSERT(!s_Instance, "Application already exists.");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		Renderer::Init();
		ImGuiLayer::Init();

	}

	Application::~Application() {
		ImGuiLayer::Shutdown();
	}



	void Application::OnEvent(Event& e) {
		
		EventDispatcher dispatcher(e);
		// If event is window close event, dispatch event to Application::OnWindowClose
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));

		SceneStateMachine::instance()->OnEvent(e);

	}

	void Application::Run() {


		while (m_Running) {

			float time = (float)glfwGetTime();
			Timestep deltaTime = time - m_LastDeltaTime;
			m_LastDeltaTime = time;

			SceneStateMachine::instance()->Update(deltaTime, m_Minimized);

			m_Window->OnUpdate();
		}

	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e) {
		
		if (e.GetWidth() == 0 || e.GetHeight() == 0) {
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;

		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}

}