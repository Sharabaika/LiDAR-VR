#pragma once
#define INIT_COMPONENT(ComponentClass, Member, ...) Member{ ObjectInitializer.CreateDefaultSubobject<ComponentClass>(this, GET_MEMBER_NAME_CHECKED(ThisClass, Member), ##__VA_ARGS__) }
