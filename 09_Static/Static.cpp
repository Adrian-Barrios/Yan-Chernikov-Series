static int s_Variable = 5; // If not static, will produce a linking error in main.cpp

static void Function()
{

}

// Static outside a class: Linkage of static symbol is going to be internal. Only visible to the current translation unit.

// Static in class: There is only one instance of a static variable across multiple class instances.