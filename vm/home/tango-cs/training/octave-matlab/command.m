% Tango Training for ELI-BL
% octave/matlab bindings
% command execution example
%
% C. Scafuri
%


% use variables to handle device name and command name


% Argin: devVoid , Argout: devVoid
devname = 'sys/tg_test/1';
cmdname = 'SwitchStates';
tango_state(devname)

tango_command_inout(devname,cmdname);
if (tango_error == -1)
    % handle error !!!!!
    tango_print_error_stack;
end

tango_state(devname)



% Argin devFloat, Argout: devFloat

cmdname='DevFloat';
inval = single(1.23); 
outval = tango_command_inout(devname,cmdname,inval);
if (tango_error == -1)
    % handle error !!!!!
    tango_print_error_stack;
end

% be careful with the types 
cmdname='DevDouble';
inval = single(1.23); 
outval = tango_command_inout(devname,cmdname,inval);
if (tango_error == -1)
    % handle error !!!!!
    tango_print_error_stack;
end