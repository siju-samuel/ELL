#
# cmake file for python model gallery utilities
#

if(${PYTHON_ENABLED})

    set(module_name "pythonlibs_gallery")

    set(lib_src copy_validation_set.py
        generate_md.py
        model_info_retriever.py
        plot_model_stats.py
        run_validation.py
        validate.py
        validate.sh.in
        vision_model.md.in
        zip_file.py)

    add_custom_target(${module_name} DEPENDS SOURCES ${lib_src})

    set_property(TARGET ${module_name} PROPERTY FOLDER "tools/utilities")
    # copy files
    foreach(PY_FILE ${lib_src})
        configure_file(${PY_FILE} ${PY_FILE} COPYONLY)
    endforeach()

endif()  # PYTHON_ENABLED
