 # project name and programming language
    project('com.github.rbribeiro.dropboxgui', 'vala', 'c')

    # Create a new executable, list the files we want to compile, list the dependencies we need, and install
    executable(
        meson.project_name(),
        'src/Application.vala',
        'src/Views/ShareView.vala',
        'src/Views/SettingsView.vala',
        'src/Views/SettingsPreferencesView.vala',
        'src/Views/MainWindowView.vala',
        'src/Widgets/StatusBar.vala',
        'src/Services/Dropbox.vala',
        'src/Windows/SettingsWindow.vala',
        dependencies: [
            dependency('gtk+-3.0'),
            dependency('unity'),
            dependency('granite')
        ],
        install: true
    )

    #Install our .desktop file so the Applications Menu will see it
    install_data(
        join_paths('data', meson.project_name() + '.desktop'),
        install_dir: join_paths(get_option('datadir'), 'applications')
    )

    #Install our .appdata.xml file so AppCenter will see it
    install_data(
        join_paths('data', meson.project_name() + '.appdata.xml'),
        install_dir: join_paths(get_option('datadir'), 'metainfo')
    )
    
    install_data (
        'data/gschema.xml',
        install_dir: join_paths (get_option ('datadir'), 'glib-2.0', 'schemas'),
        rename: meson.project_name () + '.gschema.xml'
)
    
    
