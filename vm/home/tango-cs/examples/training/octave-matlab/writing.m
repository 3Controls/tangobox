% Tango Training for ELI-BL
% octave/matlab bindings
% reading attributes example
%
% C. Sacfuri
%


% use variables to handle device name and attibute name

devname = 'sys/tg_test/1';
attname = 'double_scalar';

%first write a new value

newvalue =2.618;

tango_write_attribute(devname,attname,newvalue);

if (tango_error == -1)
% handle error !!!!!
tango_print_error_stack;
return;
else %verfy what has been written
    res = tango_read_attribute(devname,attname);
    if (tango_error == -1)
        % handle error !!!!!
        tango_print_error_stack;
    return;
    else
        % reading ok, analyze result
        disp(sprintf('attribute %s value: %f',attname,res.value(1)));
        disp(sprintf('actual set point: %f',res.value(2)));
        disp(sprintf('quality factor: %s',res.quality_str));
    end
end


% writing 'spctrum'

b=linspace(0,100.0,256); %build ramp of values
tango_write_attribute(devname,'double_spectrum',b);
if (tango_error == -1)
    % handle error !!!!!
    tango_print_error_stack;
    return;
end

% check result
a= tango_read_attribute(devname,'double_spectrum');
if (tango_error == -1)
    % handle error !!!!!
    tango_print_error_stack;
    return;
end

%plot the values, shifting one curve down by 10.0 for clarity
plot(a.value);
hold;
plot(b - 10.0);
waitforbuttonpress()