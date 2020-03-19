public class SettingsPreferencesPage : Granite.SimpleSettingsPage {
        public SettingsPreferencesPage () {
            var user_name = Environment.get_user_name ();
            var avatar = @"/var/lib/AccountsService/icons/$user_name";

            Object (
                display_widget : new Granite.Widgets.Avatar.from_file (avatar, 32),
                title : "Preferences",
                description : "User preferences",
                status : user_name,
                header : "User Settings"
            );

        }

        construct {
            
            var utils =  new Utils();

            var gtk_settings = Gtk.Settings.get_default ();

            var always_on_top_label = new Gtk.Label ("Always on top ");
            var always_on_top_swtich = new Gtk.Switch ();

            var startup_label = new Gtk.Label ("Run on startup ");
            var startup_swtich = new Gtk.Switch ();
            startup_swtich.active = is_autostart();
            startup_swtich.state_set.connect ( toggle_autostart);


            var theme_label = new Gtk.Label ("Theme mode");
            var theme_swtich = new Granite.ModeSwitch.from_icon_name (
            "display-brightness-symbolic",
            "weather-clear-night-symbolic"
            );
            theme_swtich.bind_property ("active", gtk_settings, "gtk_application_prefer_dark_theme");
            
            utils.glib_settings.bind ("darktheme-setting", theme_swtich, "active", GLib.SettingsBindFlags.DEFAULT);
            utils.glib_settings.bind("always-on-top", always_on_top_swtich, "active", GLib.SettingsBindFlags.DEFAULT);

            startup_label.halign = theme_label.halign =Gtk.Align.START;

            var grid = new Gtk.Grid ();
            grid.orientation = Gtk.Orientation.VERTICAL;
            grid.halign = Gtk.Align.CENTER;
            grid.column_spacing = grid.row_spacing = grid.margin = 12;
            grid.attach (always_on_top_label, 0,0,1,1);
            grid.attach (always_on_top_swtich, 1,0,1,1);
            grid.attach (startup_label, 0,1, 2, 1);
            grid.attach (startup_swtich, 1,1, 1, 1);
            grid.attach (theme_label, 0, 2, 1, 1);
            grid.attach (theme_swtich, 1, 2, 3, 1);

            content_area.add (grid);


        }
        
        private bool is_autostart () {
            string home = Environment.get_home_dir();
            string desktop_file_name = "com.github.rbribeiro.dropboxgui.desktop";
            GLib.File file = GLib.File.new_for_path( home+"/.config/autostart/"+desktop_file_name);
            
            return file.query_exists (); 
            
        }
        
        private bool toggle_autostart (bool s) {
            string home = Environment.get_home_dir();
            
            string stdout, stderr;
            int exit_status;
            string desktop_file_name = "com.github.rbribeiro.dropboxgui.desktop";
            string config_path = home+"/.config/autostart/"+desktop_file_name;
            string schemas_path = "/usr/share/applications/"+desktop_file_name;
           
            
            if(s) {
                string cp_cmd = "cp "+schemas_path+" "+config_path;
                 
                Process.spawn_command_line_sync (cp_cmd, out stdout, out stderr, out exit_status);
                return false;
            } else {
                Process.spawn_command_line_sync ("rm "+config_path);
                return false;
            }
        }
}
