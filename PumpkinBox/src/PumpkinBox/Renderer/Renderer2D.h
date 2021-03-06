#pragma once

#include "Cameras/OrthographicCamera.h"
#include "PumpkinBox/Renderer/Texture.h"
#include "PumpkinBox/Renderer/Renderer.h"

namespace pb {

	class Renderer2D {

	public:

		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

		// Primitives
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color = glm::vec4(1.0f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color = glm::vec4(1.0f));
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec2& tileScale = { 1.0f, 1.0f }, const glm::vec4& color = glm::vec4(1.0f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, const glm::vec2& tileScale = { 1.0f, 1.0f }, const glm::vec4& color = glm::vec4(1.0f));

		static void DrawSprite(const int& index, const glm::vec3& position, const float size, const Ref<Texture2D>& texture, int rows=1, int cols=1, const glm::vec2& tileScale = { 1.0f, 1.0f }, const glm::vec4& color = glm::vec4(1.0f));
		static void DrawSprite(const int& index, const glm::vec2& position, const float size, const Ref<Texture2D>& texture, int rows=1, int cols=1, const glm::vec2& tileScale = { 1.0f, 1.0f }, const glm::vec4& color = glm::vec4(1.0f));

	};
}