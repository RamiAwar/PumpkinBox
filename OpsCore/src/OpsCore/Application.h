#pragma once

#include "OpsCore/Core.h"
#include "Window.h"

#include "OpsCore/LayerStack.h"
#include "Events/Event.h"
#include "OpsCore/Events/ApplicationEvent.h"

#include "OpsCore/ImGui/ImGuiLayer.h"

#include "OpsCore/Renderer/Shader.h"
#include "OpsCore/Renderer/Buffer.h"
#include "OpsCore/Renderer/VertexArray.h"

namespace oc {

	class  Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		// TODO: Pop layers functionality

		inline static Application& Get() { return *s_Instance; }
		inline  Window& GetWindow() { return *m_Window; }

	private:

		static Application* s_Instance;

		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;

		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
		std::shared_ptr<VertexArray> m_VertexArray;

	};

	// Define in client
	Application* CreateApplication();

}

