#pragma once
#include "MEE_Maths.h"
#include "MEE_Exports.h"

namespace MEE
{
	class MEE_EXPORT InputManager
	{
	public:
		//TENGO QUE PONER GUAPO EL NOMBRE DE LAS FUNCIONES E INCLUIR
		// LOS DISTINTOS DISPOSITIVOS OSEA ESTO ES TEMPORAL
		bool GetKeyDown(int);
		bool GetKeyPressed(int);
		bool GetKeyUp(int);

		bool GetControllerKeyDown(int,int);
		bool GetControllerKeyPressed(int,int);
		bool GetControllerKeyUp(int,int);

		Vector2 GetMouse();
	};
}


