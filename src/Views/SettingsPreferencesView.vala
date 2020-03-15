public class SettingsPreferencesPage : Granite.SimpleSettingsPage {
        public SettingsPreferencesPage () {
            var user_name = Environment.get_user_name ();
            var avatar = @"/var/lib/AccountsService/icons/$user_name";

            Object (
                display_widget : new Granite.Widgets.Avatar.from_file (avatar, 32),
                title : "Preferences",
                description : "User preferences",
                status : user_name
            );

        }

        construct {
        
            var glib_settings =  new GLib.Settings ("com.valacounterapp");
            
            var gtk_settings = Gtk.Settings.get_default ();

            var always_on_top_label = new Gtk.Label ("Always on top ");
            var always_on_top_swtich = new Gtk.Switch ();

            var startup_label = new Gtk.Label ("Run on startup ");
            var startup_swtich = new Gtk.Switch ();
            

            var theme_label = new Gtk.Label ("Theme mode");
            var theme_swtich = new Granite.ModeSwitch.from_icon_name (
            "display-brightness-symbolic",
            "weather-clear-night-symbolic"
            );
            
            theme_swtich.bind_property ("active", gtk_settings, "gtk_application_prefer_dark_theme");
           // theme_swtich.bind_property ("active", glib_settings)

            startup_label.halign = theme_label.halign =Gtk.Align.START;
            
            var grid = new Gtk.Grid ();
            grid.orientation = Gtk.Orientation.VERTICAL;
            grid.halign = Gtk.Align.START;
            grid.column_spacing = grid.row_spacing = grid.margin = 12;
            grid.attach (always_on_top_label, 0,0,1,1);
            grid.attach (always_on_top_swtich, 1,0,1,1);
            grid.attach (startup_label, 0,1, 2, 1);
            grid.attach (startup_swtich, 1,1, 1, 1);
            grid.attach (theme_label, 0, 2, 1, 1);
            grid.attach (theme_swtich, 1, 2, 3, 1);

            content_area.add (grid);


        }
}
