#include <OpsCore.h>
#include "imgui.h"


class ExampleLayer : public oc::Layer {

public:

	ExampleLayer();

	void OnUpdate() override;
	void OnEvent(oc::Event& event) override;
	virtual void OnImGuiRender() override;

private:

	oc::Orthographic2DCamera m_Camera;

	// ------- Triangle inits ---------------------------
	float triangle_vertices[3 *3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f, 
			 0.0f, 0.5f, 0.0f, 
	};

	uint32_t triangle_indices[3] = { 0, 1, 2 };

	oc::BufferLayout triangleLayout = {
		{ oc::ShaderDataType::Float3, "a_pos"}	
	};

	std::shared_ptr<oc::VertexBuffer> triangle_vb;
	std::shared_ptr<oc::VertexArray> triangle_va;
	std::shared_ptr<oc::IndexBuffer> triangle_ib;


	// ----------- Square inits ---------------------------
	float square_vertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f
	};

	uint32_t square_indices[6] = { 0, 1, 2, 2, 3, 1 };

	oc::BufferLayout squareLayout = {
		{oc::ShaderDataType::Float3, "a_pos"}
	};

	std::shared_ptr<oc::VertexBuffer> square_vb;
	std::shared_ptr<oc::VertexArray> square_va;
	std::shared_ptr<oc::IndexBuffer> square_ib;

	std::shared_ptr<oc::Shader> triangle_shader;
	std::shared_ptr<oc::Shader> square_shader;

	glm::vec3 m_CameraPosition;
	float m_CameraMovementSpeed = 0.1f;

	float m_CameraRotationSpeed = 1.0f;
	float m_CameraRotation = 0.0f;

	std::string triangle_vertex_shader_src = { R"(

			#version 330 core 
			
			layout (location = 0) in vec3 a_Position;
			
			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main(){
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position.x, a_Position.y, a_Position.z, 1.0);	
			}
		)" };

	std::string square_vertex_shader_src = { R"(

			#version 330 core 
			
			layout (location = 0) in vec3 a_Position;
			
			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main(){
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position.x, a_Position.y, a_Position.z, 1.0);	
			}
		)" };

	std::string triangle_fragment_shader_src = { R"(
			#version 330 core 
			
			layout (location = 0) out vec4 color;
			
			in vec3 v_Position;

			void main(){
				color = vec4(v_Position.x + 0.5, v_Position.y + 0.1, 0.5, 1.0);	
			}

		)" };

	std::string square_fragment_shader_src = { R"(
			#version 330 core 
			
			layout (location = 0) out vec4 color;
			
			in vec3 v_Position;
			void main(){
				color = vec4(v_Position.x + 0.1, v_Position.y + 0.2, 0.5, 1.0);	
		 	}

		)" };


};