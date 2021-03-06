﻿#pragma once

#include <string>
#include "..\Common\DeviceResources.h"
#include "..\Common\StepTimer.h"
#include "TextRenderer.h"

namespace CPPHelloDirectX
{
	// Renders the current FPS value in the bottom right corner of the screen using Direct2D and DirectWrite.
	class SampleFpsTextRenderer : public TextRenderer
	{
	public:
		SampleFpsTextRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		
		void Update(DX::StepTimer const& timer) override;
		
		void Render() override;
		
		
	};
}