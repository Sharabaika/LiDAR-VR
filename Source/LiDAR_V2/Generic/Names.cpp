#include "Names.h"

#define DEFINE_NAME_WITH_CATEGORY(Category, Name) FName Category::Name{ TEXT(#Name) }
#define DEFINE_NAME(Name) FName Name{ TEXT(#Name) }


// Input //
// ===== //
DEFINE_NAME_WITH_CATEGORY(InputNames, Strafe);
DEFINE_NAME_WITH_CATEGORY(InputNames, MoveFrontBack);
DEFINE_NAME_WITH_CATEGORY(InputNames, Turn);

DEFINE_NAME_WITH_CATEGORY(InputNames, GripLeft);
DEFINE_NAME_WITH_CATEGORY(InputNames, GripRight);

DEFINE_NAME_WITH_CATEGORY(InputNames, GripLeftAxis);
DEFINE_NAME_WITH_CATEGORY(InputNames, GripRightAxis);

DEFINE_NAME_WITH_CATEGORY(InputNames, TriggerLeft);
DEFINE_NAME_WITH_CATEGORY(InputNames, TriggerRight);

DEFINE_NAME_WITH_CATEGORY(InputNames, TriggerLeftAxis);
DEFINE_NAME_WITH_CATEGORY(InputNames, TriggerRightAxis);


// Fake input //
// ========== //
DEFINE_NAME_WITH_CATEGORY(InputNames, EnableFakeVRMode);

DEFINE_NAME_WITH_CATEGORY(InputNames, FakeVRCamera_Pitch);

DEFINE_NAME_WITH_CATEGORY(InputNames, FakeVRController_X);
DEFINE_NAME_WITH_CATEGORY(InputNames, FakeVRController_Y);
DEFINE_NAME_WITH_CATEGORY(InputNames, FakeVRController_Z);

